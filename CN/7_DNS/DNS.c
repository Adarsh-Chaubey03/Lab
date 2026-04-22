#include<stdio.h>
#include<string.h>

int main(){
	char name[50],ip[50],fname[50],fip[50];
	FILE *fp;
	fp = fopen("dns.txt","r");
	if(fp == NULL){
		printf("File not found | Error in Open file\n");
		return 0;
	}
	int n;
	printf("Enter the choice:\n 1.  Forward Mode \n 2. Backward Mode\n");
	scanf("%d",&n);

	if(n == 1){
		printf("Enter the Name of Server: ");
		scanf("%s",name);

		while(fscanf(fp,"%s %s",fname,fip)!=EOF){
			if(strcmp(name,fname)==0){
				printf("IP address of Server is : %s\n",fip);
			}
		}
	}
	else if(n == 2){
		printf("Enter the IP address of Server: ");
		scanf("%s",ip);

		while(fscanf(fp,"%s %s",fname,fip)!=EOF){
			if(strcmp(ip,fip)==0){
				printf("Name of the Server is : %s\n",fname);
			}
		}
	}
	else{
		printf("Error! You Entered wrong choice\n");
	}

	fclose(fp);

	return 0;

}
