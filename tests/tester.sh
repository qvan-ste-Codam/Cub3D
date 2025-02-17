#!/bin/bash
CUB3D_EXEC=../cub3D
MAPS_FOLDER=./maps
TEST_RESULT=0
TEST_COUNT=0
SUCCES_COUNT=0
FAIL_COUNT=0
RECOMPILE=false

RED='\033[0;31m'
ORANGE='\033[0;33m'
GREEN='\033[0;32m'
NO_COLOUR='\033[0m'

# Recomplie with debug flag
while [ "$1" != "" ]; do
    case $1 in
        -re ) RECOMPILE=true
              ;;
        * )   echo "Invalid option: $1"
              exit 1
    esac
    shift
done

if [ "$RECOMPILE" = true ]; then
    echo "Recompiling..."
    (cd .. && make debug)
fi

# Change permisisons for files. If kept at 000 it can't be added to the repo
(chmod 000 ./textures/invalid_permissions.png && chmod 000 ./maps/invalid_permissions.cub)

# Chek for every file if exit is error
for MAP_FILE in $MAPS_FOLDER/*.cub; do

    echo -e "\n${ORANGE}Testing $MAP_FILE...${NO_COLOUR}"
    
    $CUB3D_EXEC $MAP_FILE
    EXIT_CODE=$?
    ((TEST_COUNT++))

    if [ $EXIT_CODE -eq 0 ]; then
        echo -e "${RED}Test failed for $MAP_FILE ${NO_COLOUR}"
        ((FAIL_COUNT++))
        TEST_RESULT=1
    else
        echo -e "${GREEN}Test passed for $MAP_FILE${NO_COLOUR}"
        ((SUCCES_COUNT++))
    fi
done

((SUCCES_COUNT - FAIL_COUNT))

if [ $SUCCES_COUNT -eq $TEST_COUNT ]; then
    echo -e "\n${GREEN}All tests passes ${SUCCES_COUNT}/${TEST_COUNT}${NO_COLOUR}"
else
    echo -e "\n${RED}Tests succeeded ${SUCCES_COUNT}/${TEST_COUNT}${NO_COLOUR}"
fi

# Reset permissions
(chmod 777 ./textures/invalid_permissions.png && chmod 777 ./maps/invalid_permissions.cub)

exit $TEST_RESULT