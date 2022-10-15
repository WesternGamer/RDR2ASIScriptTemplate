#pragma once
#include <string>
#include <stdio.h>
#include <stdlib.h>

//Credit: https://stackoverflow.com/questions/25328212/writing-in-an-ini-file
namespace Config
{
    // module variables
    int                 iFoundTopic;
    int                 iFoundItem;
    int                 iError;
    long                lTopicFilePos;
    char                acTopicHeading[80];
    char                acLastTopicHeading[80];
    char                acItemHeading[80];
    char                acIniLine[160];
    char                acIniPath[160];
    char                acTempPath[160];
    FILE* pFIniFile;
    FILE* pFTempIni;

    // saveinis
    // save configuration string
    int saveinis(char* pacPath, char* pacTopic, char* pacItem, char* pacValue) {
        int                 iItemLength;
        int                 iValueLength;

        iError = 0;
        acLastTopicHeading[0] = '\0';

        strcpy(acIniPath, pacPath);

        strcpy(acTempPath, pacPath);
        strcat(acTempPath, "temp");

        // add brackets to topic
        strcpy(acTopicHeading, "[");
        strcat(acTopicHeading, pacTopic);
        strcat(acTopicHeading, "]\n");

        strcpy(acItemHeading, pacItem);
        strcat(acItemHeading, "=");

        iItemLength = strlen(acItemHeading);
        iValueLength = strlen(pacValue);

        iFoundTopic = 0;
        iFoundItem = 0;

        if ((pFTempIni = fopen(acTempPath, "w")) == NULL) {
            printf("could not open temp ini file to write settings\n");
            iError = 1;
            return (iError);
        }

        // try to open current config file for reading
        if ((pFIniFile = fopen(acIniPath, "r")) != NULL) {
            // read a line from the config file until EOF
            while (fgets(acIniLine, 159, pFIniFile) != NULL) {
                // the item has been found so continue reading file to end
                if (iFoundItem == 1) {
                    fputs(acIniLine, pFTempIni);
                    continue;
                }
                // topic has not been found yet
                if (iFoundTopic == 0) {
                    if (strcmp(acTopicHeading, acIniLine) == 0) {
                        // found the topic
                        iFoundTopic = 1;
                    }
                    fputs(acIniLine, pFTempIni);
                    continue;
                }
                // the item has not been found yet
                if ((iFoundItem == 0) && (iFoundTopic == 1)) {
                    if (strncmp(acItemHeading, acIniLine, iItemLength) == 0) {
                        // found the item
                        iFoundItem = 1;
                        if (iValueLength > 0) {
                            fputs(acItemHeading, pFTempIni);
                            fputs(pacValue, pFTempIni);
                            fputs("\n", pFTempIni);
                        }
                        continue;
                    }
                    // if newline or [, the end of the topic has been reached
                    // so add the item to the topic
                    if ((acIniLine[0] == '\n') || (acIniLine[0] == '[')) {
                        iFoundItem = 1;
                        if (iValueLength > 0) {
                            fputs(acItemHeading, pFTempIni);
                            fputs(pacValue, pFTempIni);
                            fputs("\n", pFTempIni);
                        }
                        fputs("\n", pFTempIni);
                        if (acIniLine[0] == '[') {
                            fputs(acIniLine, pFTempIni);
                        }
                        continue;
                    }
                    // if the item has not been found, write line to temp file
                    if (iFoundItem == 0) {
                        fputs(acIniLine, pFTempIni);
                        continue;
                    }
                }
            }
            fclose(pFIniFile);
        }
        // still did not find the item after reading the config file
        if (iFoundItem == 0) {
            // config file does not exist
            // or topic does not exist so write to temp file
            if (iValueLength > 0) {
                if (iFoundTopic == 0) {
                    fputs(acTopicHeading, pFTempIni);
                }
                fputs(acItemHeading, pFTempIni);
                fputs(pacValue, pFTempIni);
                fputs("\n\n", pFTempIni);
            }
        }

        fclose(pFTempIni);

        //delete the ini file
        remove(acIniPath);

        // rename the temp file to ini file
        rename(acTempPath, acIniPath);

        return (iError);
    }

    // readinis
    // read configuration string
    int readinis(char* pacPath, char* pacTopic, char* pacItem, char* pacValue) {
        int                 iItemLength;
        int                 iValueLength;
        char* pcLastCharacter;

        iError = 0;

        strcpy(acIniPath, pacPath);

        // add brackets to topic
        strcpy(acTopicHeading, "[");
        strcat(acTopicHeading, pacTopic);
        strcat(acTopicHeading, "]\n");

        strcpy(acItemHeading, pacItem);
        strcat(acItemHeading, "=");

        iItemLength = strlen(acItemHeading);

        iFoundTopic = 0;
        iFoundItem = 0;

        // try to open current config file for reading
        if ((pFIniFile = fopen(acIniPath, "r")) != NULL) {
            // has the topic been found before
            if (strcmp(acLastTopicHeading, acTopicHeading) == 0) {
                iFoundTopic = 1;
                fseek(pFIniFile, lTopicFilePos, SEEK_SET);
            }

            // read a line from the config file until EOF
            while (fgets(acIniLine, 159, pFIniFile) != NULL) {
                // topic has not been found yet
                if (iFoundTopic == 0) {
                    if (strcmp(acTopicHeading, acIniLine) == 0) {
                        // found the topic
                        iFoundTopic = 1;
                        lTopicFilePos = ftell(pFIniFile);
                        strcpy(acLastTopicHeading, acTopicHeading);
                    }
                    continue;
                }
                // the item has not been found yet
                if ((iFoundItem == 0) && (iFoundTopic == 1)) {
                    // if newline or [, the end of the topic has been reached
                    // no config value in file yet
                    if ((acIniLine[0] == '\n') || (acIniLine[0] == '[')) {
                        iFoundItem = 1;
                        break;
                    }

                    if (strncmp(acItemHeading, acIniLine, iItemLength) == 0) {
                        // found the item
                        iFoundItem = 1;
                        strcpy(pacValue, &acIniLine[iItemLength]);
                        continue;
                    }
                }
            }
            fclose(pFIniFile);
        }
        // remove trailing comment
        iValueLength = strlen(pacValue);
        while (iValueLength) {
            if (*(pacValue + iValueLength) == '#') {
                *(pacValue + iValueLength) = '\0';
            }
            iValueLength--;
        }
        // remove trailing white space
        while ((iValueLength = strlen(pacValue)) > 0) {
            pcLastCharacter = (pacValue + iValueLength - 1);
            if ((*pcLastCharacter == ' ')
                || (*pcLastCharacter == '\n')
                || (*pcLastCharacter == '\r')
                || (*pcLastCharacter == '\t')
                || (*pcLastCharacter == '\v')
                || (*pcLastCharacter == '\a')
                || (*pcLastCharacter == '\b')
                || (*pcLastCharacter == '\f')) {
                *pcLastCharacter = '\0';
            }
            else {
                break;
            }
        }

        return (iError);
    }
}