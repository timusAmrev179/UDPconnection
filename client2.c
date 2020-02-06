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
	
	if(sockfd != -1)
		printf("\nsocket successful!"); 
	else
		printf("\nsocket failure"); 

	struct sockaddr_in sen; 
	sen.sin_port = htons(5000); 
	sen.sin_addr.s_addr = INADDR_ANY; 
	sen.sin_family = AF_INET; 	
	int bin = bind(sockfd, (const struct sockaddr *)(&sen), sizeof(sen) ); 

	if(!bin)
		printf("\nbinding successful!"); 
	else 
		printf("\nbinding failure!"); 


	struct sockaddr_in dest_addr; 
	dest_addr.sin_port = htons(6000);	
	dest_addr.sin_addr.s_addr = INADDR_ANY; 
	dest_addr.sin_family = AF_INET; 


	do{	
		printf("\nType: ");
		fgets(buff, sizeof(buff), stdin);
		sento= sendto(sockfd, buff, strlen(buff), 0, (const struct sockaddr *)(&dest_addr), sizeof(dest_addr) );
		
		if(sento!= -1)
			printf("\nmessage sent!"); 
		else
			printf("\nsending failed...!") ;

		

		
		
		rcvfrm = recvfrom(sockfd, recbuff, sizeof(recbuff), 0, (struct sockaddr*)(&src_addr), &addr_len);
		

		if(rcvfrm!= -1)
			printf("\nmessage received!"); 
		else
			printf("\nreceiving failed...!") ;

		
		printf("\nserver: %s", recbuff); 


		printf("\n==================================="); 

	}while(getchar()!='~'); 	


	return 0; 

		
	
}
