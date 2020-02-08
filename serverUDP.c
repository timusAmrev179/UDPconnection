#include<stdio.h>
#include<sys/types.h>
#include<sys/socket.h>
#include <netinet/in.h>
#include <netinet/ip.h> /* superset of previous */
#include<string.h>


int main(){
	int sento, rcvfrm, addr_len; 
	int sockfd = socket(AF_INET, SOCK_DGRAM, 0); 
	char buff[100];
	char recbuff[100]={0}; 
	struct sockaddr src_addr; 
	int msglen; 

	if(sockfd != -1)
		printf("\nsocket successful!"); 
	else
		printf("\nsocket failure"); 

	struct sockaddr_in rec; 
	rec.sin_port = htons(6000); 
	rec.sin_addr.s_addr = INADDR_ANY; 
	rec.sin_family = AF_INET; 	
	int bin = bind(sockfd, (const struct sockaddr *)(&rec), sizeof(rec) ); 

	if(!bin)
		printf("\nbinding successful!"); 
	else 
		printf("\nbinding failure!"); 


	do{
		
			
		rcvfrm = recvfrom(sockfd, recbuff, sizeof(recbuff), 0, (struct sockaddr*)(&src_addr), &addr_len);
		

		if(rcvfrm!= -1)
			printf("\nmessage received!"); 
		else
			printf("\nreceiving failed...!") ;

		//msglen = strlen(recbuff); 
		printf("\nclient: %s ", recbuff); 

		printf("\nType: ");
		fgets(buff, sizeof(buff), stdin);  		
		
		sento= sendto(sockfd, buff, strlen(buff), 0, &src_addr, sizeof(src_addr) );
		
		if(sento!= -1)
			printf("\nmessage sent!"); 
		else
			printf("\nsending failed...!") ;

	
		printf("\n=================================="); 
	
	}while(getchar()!='~'); 

	return 0; 
}
