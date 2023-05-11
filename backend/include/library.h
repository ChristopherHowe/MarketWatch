/*******************************
Author: Christopher Howe
Purpose: contains low level structs and functions to organize application
also has implimentation libcurl in a way I am kinda familiar with
********************************/

#ifndef LIB_STRUCTS_H
#define LIB_STRUCTS_H

#include <iostream>
#include <cstring>
#include <ctime>
#include <curl/curl.h>


#define MAX_USERS 10

struct ApiConfig {
    std::string domain;
    std::string key;
};

struct Query {
  std::string queryString;
  std::string symbol;
  int vals;
};

struct Response{
  std::string body;
  long status;
};

//https://stackoverflow.com/questions/2329571/c-libcurl-get-output-into-a-string

struct bString {
  char *ptr;
  size_t len;
};

void init_string(struct bString *s);

size_t writefunc(void *ptr, size_t size, size_t nmemb, struct bString *s);


// end citation


//This wrapper function makes libcurl something I can understand after working with js and python
// Syntax is from libcurl documentation
Response curlWrap(std::string url);

std::string time_tToStr(time_t time);
#endif
