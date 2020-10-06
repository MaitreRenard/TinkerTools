#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include <b64.h>
#include <ccan/json.h>
#include <openssl/hmac.h>

#include "jwt.h"

const char delim[2] = ".";
const char space[2] = " ";

bool json_exists(JsonNode* json_node, const char* key) {
	return (json_find_member(json_node, key) != NULL);
}

jwt_token* parse_jwt(char* encoded_data) {
	if (strchr(encoded_data, delim[0]) != NULL) {
		char *token_part, *dec;
		jwt_token* token = malloc(sizeof(jwt_token));

		token->encoded = encoded_data;

		token_part = strtok(token->encoded, delim);
		parse_header(token);

		token_part = strtok(NULL, delim);
		parse_payload(token);

		token_part = strtok(NULL, delim);
		parse_signature(token);

		return token;
	}

	return NULL;
}

void parse_header(jwt_token* jtkn) {
	JsonNode *part_data, *tmp_child;
	char *dec = (char*) b64_decode(jtkn->encoded, strlen(jtkn->encoded));
	part_data = json_decode(dec);
	if (json_exists(part_data,"alg")) {
		printf("%s\n", json_stringify(json_find_member(part_data, "alg"), space));
	}

}

void parse_payload(jwt_token* jtkn) {
}

void parse_signature(jwt_token* jtkn) {
}

int main(int argc, char **argv) {
	if(argc > 1) {
		jwt_token *token = parse_jwt(argv[1]);
		if (token) {
			puts("youpi");
		} else {
			puts("Could not parse the JWT token.");
		}
		//unsigned char *dec = b64_decode(token_part, strlen(token_part));
	} else {
		printf("%s takes at least one argument.\n", argv[0]);
	}

	return 0;
}
