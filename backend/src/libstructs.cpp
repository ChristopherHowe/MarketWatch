#include "libstructs.h"

void init_string(struct bString *s) {
  s->len = 0;
  s->ptr = (char*)malloc(s->len+1);
  if (s->ptr == NULL) {
    fprintf(stderr, "malloc() failed\n");
    exit(EXIT_FAILURE);
  }
  s->ptr[0] = '\0';
}

size_t writefunc(void *ptr, size_t size, size_t nmemb, struct bString *s)
{
  size_t new_len = s->len + size*nmemb;
  s->ptr = (char*)realloc(s->ptr, new_len+1);
  if (s->ptr == NULL) {
    fprintf(stderr, "realloc() failed\n");
    exit(EXIT_FAILURE);
  }
  memcpy(s->ptr+s->len, ptr, size*nmemb);
  s->ptr[new_len] = '\0';
  s->len = new_len;

  return size*nmemb;
}

Response curlWrap(std::string url){
  CURL *curl;
  CURLcode res;

  curl = curl_easy_init();
    if(curl) {
        struct bString s;
        long http_code;
        init_string(&s);


        curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, writefunc);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &s);
        res = curl_easy_perform(curl);
        curl_easy_getinfo (curl, CURLINFO_RESPONSE_CODE, &http_code);

        curl_easy_cleanup(curl);
        return Response{s.ptr,http_code};
    }
    throw std::runtime_error("failed to start curl");
}

std::string time_tToStr(time_t time){
  std::tm * ptm = std::localtime(&time);
  char buffer[32];
  std::strftime(buffer, 32, "%m/%d/%Y %H:%M:%S", ptm); 
  std::string result(buffer);
  return result; 
}
