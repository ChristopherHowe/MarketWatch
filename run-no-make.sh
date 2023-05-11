source ./env.sh

if [ -z $TWELVE_KEY ]; 
    then
    echo failed to load in stock API key, make sure twelve-data-token is in ~/personal directory
    echo exiting...
    exit
fi
if [ -z $API_DOMAIN ]; 
    then
    echo failed to load in API Domain, make sure it is specified in the env.sh file
    echo exiting...
    exit
fi

./marketwatch