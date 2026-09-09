/* C | string: caesar cipher. */
void Caesar(char str[],int k , char out[]){
	int n  = strlen(str);
	for(int  i = 0 ;i<n;i++){
		if(str[i]>='a' && str[i]<='z'){
			out[i] = (str[i]-'a'+k+26)%26 + 'a';
		}
		else if(str[i]>='A' && str[i]<='Z'){
			out[i] = (str[i]-'a'+k+26)%26 + 'A';
		}
		else{
			out[i] = str[i];
		}
	}
	out[n] = 0 ;//结束符 
}
