#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include <b64.h>
#include <json.h>
#include <openssl/hmac.h>

#include "jwt.h"

const char delim[2] = ".";
const char space[2] = " ";

jwt_token* parse_jwt(char* encoded_data) {
	char *token_part, *dec;
	jwt_token* token = malloc(sizeof(jwt_token));

	token->encoded = encoded_data;

	token_part = strtok(token->encoded, delim);
	dec = (char*) b64_decode(token_part, strlen(token_part));
	parse_header(token);

	token_part = strtok(NULL, delim);
	parse_payload(token);

	token_part = strtok(NULL, delim);
	parse_signature(token);

}

void parse_header(jwt_token* jtkn) {
	JsonNode *part_data, *tmp_child;
}

void parse_payload(jwt_token* jtkn) {
}

void parse_signature(jwt_token* jtkn) {
}

bool json_exists(JsonNode* json_node, const char* key) {
	return (json_find_member(json_node, key) != NULL);
}

int main(int argc, char **argv) {
	if(argc > 1) {

		//unsigned char *dec = b64_decode(token_part, strlen(token_part));
	} else {
		printf("%s takes at least one argument.\n", argv[0]);
	}

	return 0;
}
