#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <arpa/inet.h>
/*引入连接Mysql的头文件*/
#include "/usr/include/mysql/mysql.h"
#include <pthread.h>

#define HOST "localhost" /*MySql服务器地址*/
#define USERNAME "root" /*用户名*/
#define PASSWORD "dD392817" /*数据库连接密码*/
#define DATABASE "smarthome" /*需要连接的数据库*/

//信息结构体
struct SockInfo
{
	struct sockaddr_in addr;
	int fd;
};
struct SockInfo infos[512];


void* working(void* arg);

int main()
{
	//1.创建套接字
	int fd = socket(AF_INET, SOCK_STREAM, 0);
	if(fd == -1){
		perror("socket");
		return -1;	
	}

	//2.绑定本地的IP port
	struct sockaddr_in saddr;
	saddr.sin_family = AF_INET;
	saddr.sin_port = htons(12345);
	saddr.sin_addr.s_addr = INADDR_ANY;
	int ret = bind(fd,(struct sockaddr*)&saddr, sizeof(saddr));
	if(ret == -1){
        perror("bind");
        return -1;
	}

	//3.设置监听
	ret = listen(fd, 128);
	if(ret == -1){
		perror("listen");
		return -1;
	}

	//初始化结构体数组
	int max = sizeof(infos) / sizeof(infos[0]);
	int j = 0;
	for(j=0; j<max; ++j){
		bzero(&infos[j], sizeof(infos[j]));
		infos[j].fd= -1;
	}

	//4. 阻塞并等待客户端的连接
	int addrlen = sizeof(struct sockaddr_in);
	while(1){
		struct SockInfo* pinfo;
		int i=0;
		for(i=0;i<max;++i){
			if(infos[i].fd == -1){
				pinfo = &infos[i];
				break;
			}
		}
		int cfd = accept(fd, (struct sockaddr*)&pinfo->addr, &addrlen);
		pinfo->fd = cfd;
		if(cfd == -1){
			perror("accept");
			break;
		}
		//创建子线程
		pthread_t tid;
		pthread_create(&tid,NULL,working, pinfo);
		pthread_detach(tid);
	}
	close(fd);

	return 0;
}

void* working(void* arg){

	struct SockInfo* pinfo = (struct SockInfo*)arg;
	//连接建立成功，打印客户端的IP和端口信息
	char ip[32];
	printf("客户端的IP：%s， 端口：%d\n", inet_ntop(AF_INET, &pinfo->addr.sin_addr.s_addr, ip, sizeof(ip)), ntohs(pinfo->addr.sin_port));
		
	//5. 连接MySQL
	MYSQL my_connection; /*数据库连接*/ 
	MYSQL_RES* res_ptr; /*执行结果*/ 
	MYSQL_RES* res1;
	const char *sql = "select * from changeflag";/*查询语句*/
	char sql_air[1024];
	char sql_flag[1024];
	char sql_cmd[1024];
	MYSQL_ROW result_row,result_air; /*按行返回查询信息*/ 
	int row;/*行数*/
	mysql_init(&my_connection);
	mysql_real_connect(&my_connection, HOST, USERNAME, PASSWORD, DATABASE, 3306, NULL, CLIENT_FOUND_ROWS);
	//mysql_query(&my_connection, "set names utf8");
	
	//6. 通信
	char type[32];
	recv(pinfo->fd, type, sizeof(type), 0);
	if(strstr(type,"control")){
	    while(1){
    		char buff[1024];
    		mysql_query(&my_connection, sql); 
    		res_ptr = mysql_store_result(&my_connection);
    		row = mysql_num_rows(res_ptr);
    		int i;
    		for (i = 1; i < row + 1; i++) {
    			result_row = mysql_fetch_row(res_ptr);
    			if(strcmp(result_row[2],"0") == 0){}
    			else{	
    				if(strcmp(result_row[0],"light") == 0){
    					sprintf(buff, "%s%s",result_row[0], result_row[1]);
    					sprintf(sql_flag,"UPDATE changeflag SET flag=0 WHERE place='%s' AND type='%s'",result_row[1], result_row[0]);
    					mysql_query(&my_connection, sql_flag);
    					send(pinfo->fd, buff, sizeof(buff), 0);
    				}
    				else if(strcmp(result_row[0],"air") == 0){
    					sprintf(sql_air,"SELECT * FROM air WHERE Place=%s",result_row[1]); 
    					sprintf(sql_flag,"UPDATE changeflag SET flag=0 WHERE place='%s' AND type='%s'",result_row[1], result_row[0]);
    					mysql_query(&my_connection, sql_flag);
    					mysql_query(&my_connection, sql_air);
    					res1 = mysql_store_result(&my_connection);
    					result_air = mysql_fetch_row(res1);
    					sprintf(buff, "air%s %s %s %s %s",result_air[0], result_air[1], result_air[2], result_air[3],result_air[4]);
    					send(pinfo->fd, buff, sizeof(buff), 0);
    				}
    				else if(strcmp(result_row[0],"curtain") == 0){
    					sprintf(buff,"%s",result_row[0]);
    					sprintf(sql_flag,"UPDATE changeflag SET flag=0 WHERE place='%s' AND type='%s'",result_row[1], result_row[0]);
    					mysql_query(&my_connection, sql_flag);
    					send(pinfo->fd, buff, sizeof(buff), 0);
    				}
    				else if(strcmp(result_row[0],"lock") == 0){
    					sprintf(buff,"%s",result_row[0]);
    					sprintf(sql_flag,"UPDATE changeflag SET flag=0 WHERE place='%s' AND type='%s'",result_row[1], result_row[0]);
    					mysql_query(&my_connection, sql_flag);
    					send(pinfo->fd, buff, sizeof(buff), 0);
    				}
    				else if(strcmp(result_row[0],"camera") == 0){
    					sprintf(buff,"%s",result_row[0]);
    					sprintf(sql_flag,"UPDATE changeflag SET flag=0 WHERE place='%s' AND type='%s'",result_row[1], result_row[0]);
    					mysql_query(&my_connection, sql_flag);
    					send(pinfo->fd, buff, sizeof(buff), 0);
    				}
    			}
    			strcpy(sql_flag, "");
    		    strcpy(sql_air, "");
    		    strcpy(buff,"");
    		}
    	sleep(1);
    	}
    	close(pinfo->fd);	
	    pinfo->fd = -1;
	    return NULL;
	}
    else if(strstr(type,"fire")){
    	while(1){
    		char cmd[1024];
    		int len = recv(pinfo->fd, cmd, sizeof(cmd), 0);
    		if(len>0){
    			sprintf(sql_cmd,"UPDATE alarm SET flag=1 WHERE type='fire'");
    			mysql_query(&my_connection, sql_cmd);
    		}
    		strcpy(sql_cmd,"");
    		strcpy(cmd,"");
    		sleep(1);
    	}
	}
	else if(strstr(type,"invade")){
		while(1){
    		char cmd[1024];
    		int len = recv(pinfo->fd, cmd, sizeof(cmd), 0);
    		if(len>0){
    			sprintf(sql_cmd,"UPDATE alarm SET flag=1 WHERE type='invade'");
    			mysql_query(&my_connection, sql_cmd);
    		}
    		strcpy(sql_cmd,"");
    		strcpy(cmd,"");
			sleep(1);
    	}
	}
}
