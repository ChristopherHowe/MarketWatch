# MarketWatch
A simple project to get into working with AI and stock market data
The executable uses the twelve data api to gather some time series data.
It the injects it into its own system and allows the user to "make transactions" to simulate stock purchases
The goal is to eventually use this data to test some personal project trading algorithms
The api key is not committed into the repo for security reasons.

The ```env.sh``` script sets the necessary environment variables
Running ```testcmake.sh``` refreshes the cmake files and runs the project.
If you dont want to refresh cmake, run ```run.sh```

To be honest, I doubt this will build on a machine without the correct libraries set up,
I have included the executable which was compiled on amd64 ubuntu 23.04

## Valid HTTP Requests
```bash
# require httpie
http 127.0.0.1:1984/user
http 127.0.0.1:1984/purchase/position symbol="ABC" numShares=1.5 type="buy"
http 127.0.0.1:1984/stocks
```