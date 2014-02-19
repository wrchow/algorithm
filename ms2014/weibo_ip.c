/*
* @20140218 sina_weibo
* check ip address
*/

#include <stdio.h>


int isRealIp(const char* ip)
{
	int dotNum = 0;
	int section = 0; // value of section
	int secNum = 0; // sec position
/* error:	while (ip++ != NULL) { */ 
	while (*ip) {
		if (*ip == '.') {
			if (++dotNum > 3) {
				return 0;
			}
			section = 0;
		} else if (*ip >= '0' && *ip <= '9') {
			section *= 10;
			if (secNum++ > 0 && section == 0) {
				return 0;
			} 
			section += *ip - '0';
			if (section > 255) {
				return 0;
			}	
		}
		ip++;		
	}		
	if (dotNum < 3) {
		return 0;
	}
	return 1;
}

int is_valid_ip(const char *ip) 
{ 
    int section = 0;  //每一节的十进制值 
    int dot = 0;       //几个点分隔符 
    int last = -1;     //每一节中上一个字符 
    while(*ip){ 
        if(*ip == '.'){ 
            dot++; 
            if(dot > 3){ 
                return 0; 
            } 
            if(section >= 0 && section <=255){ 
                section = 0; 
            }else{ 
                return 0; 
            } 
        }else if(*ip >= '0' && *ip <= '9'){ 
            section = section * 10 + *ip - '0'; 
            if(last == '0'){ 
                return 0; 
            } 
        }else{ 
            return 0; 
        } 
        last = *ip; 
        ip++;        
    }

    if(section >= 0 && section <=255){ 
        section = 0; 
    } 
    return 1; 
}


int main()
{
	const char* ip1 = "1.1.1";
	printf("%s is %d\n", ip1, isRealIp(ip1));

	const char* ip2 = "257.1.1.1";
	printf("%s is %d\n", ip2, isRealIp(ip2));

	const char* ip3 = "1..";
	printf("%s is %d\n", ip3, isRealIp(ip3));
	 
	const char* ip4 = "255.2.3.4";
	printf("%s is %d\n", ip4, isRealIp(ip4));
	
	const char* ip5 = "00.2.3.4";
	printf("%s is %d\n", ip5, isRealIp(ip5)); // error of 00.2.3.4
	printf("%s is %d\n", ip5, is_valid_ip(ip5)); // error of 100.2.3.4

	return 0;

}
