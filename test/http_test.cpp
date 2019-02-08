#include <gtest/gtest.h>
#include "../include/NetSimulator/layer/application/http.h"
#include <iostream>

TEST(HttpRequestMessageEncode, NoHeaders) {
    std::string test_request = "GET http://www.example.com HTTP/1.1\r\n\r\n";
    size_t request_size = test_request.size();

    HTTP::RequestMessage request_message;
    request_message.method = "GET";
    request_message.url = "http://www.example.com";
    request_message.version = "HTTP/1.1";
    char* encoded_request_ = (char *) HTTP::encode(request_message);

    char* encoded_request = new char[request_size + 1];
    encoded_request[request_size + 1] = '\0';
    strncpy(encoded_request, encoded_request_, request_size);
    delete[] encoded_request_;

    ASSERT_STREQ(encoded_request, test_request.c_str());
    delete[] encoded_request;
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
