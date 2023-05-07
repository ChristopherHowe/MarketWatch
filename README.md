# MarketWatch
A simple project to get into working with AI and stock market data
The executable uses the twelve data api to gather some time series data.
It the injects it into its own system and allows the user to "make transactions" to simulate stock purchases
The goal is to eventually use this data to test some personal project trading algorithms
The api key is not committed into the repo for security reasons.

The ```env.sh``` script sets the necessary environment variables
Running ```testcmake.sh``` refreshes the cmake files and runs the project.
If you dont want to refresh cmake, run ```run.sh```