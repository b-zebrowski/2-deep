// This is a single line comment, you should not see the link to https://github.com/b-zebrowski/1-deep

/*
Now lets check a multi-line comment, you should not see a link to https://github.com/b-zebrowski/1-deep
*/
/* Another multi-line comment, you should not see a link to https://github.com/b-zebrowski/1-deep */

#include <stdio.h>
#include <curl/curl.h>

// Callback function to write received data into a buffer
size_t write_callback(void *contents, size_t size, size_t nmemb, void *userp) {
    size_t total_size = size * nmemb;
    printf("%.*s", (int)total_size, (char *)contents); // Print the response directly to stdout
    return total_size;
}

int main() {
    CURL *curl;
    CURLcode res;

    // Initialize libcurl
    curl = curl_easy_init();
    if(curl) {
        // Set the URL to request
        const char *url = "https://github.com/b-zebrowski/1-deep"; // this line you should see pointing towards 1-deep
        const char *url = "https://github.com/b-zebrowski/1-deep@123456";  // this line should not show up as it ties back to a specific tag

        // Configure libcurl
        curl_easy_setopt(curl, CURLOPT_URL, url); // Set the target URL
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_callback); // Set the callback for handling response data

        // Perform the request
        printf("Fetching URL: %s\n\n", url);
        res = curl_easy_perform(curl);

        // Check for errors
        if(res != CURLE_OK) {
            fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
        }

        // Cleanup
        curl_easy_cleanup(curl);
    } else {
        fprintf(stderr, "Failed to initialize libcurl.\n");
        return 1;
    }

    return 0;
}
