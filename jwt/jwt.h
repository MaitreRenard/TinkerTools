#ifndef __JWT_H__
#define __JWT_H__

typedef enum {
	HS256		= 0x01
} jwt_alg;

typedef struct 
{
	char* encoded;
	jwt_alg algorithm;
} jwt_token;

jwt_token* parse_jwt(char* encoded_data);
void parse_header(jwt_token* jtkn);

void parse_payload(jwt_token* jtkn);

void parse_signature(jwt_token* jtkn);

#endif /* JWT_H */
