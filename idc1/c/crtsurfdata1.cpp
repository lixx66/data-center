
#include "_public.h"
int main(int argc,char *argv[]){

//inifile气象参数文件 outpath logfile

  if(argc!=4){
	printf("Using:./crtsurfdata1 inifile putpath logfile\n");
	printf("Example:project/idc1/bin/crtsurfdata1 /project/idc1/ini/stcode.ini /tmp/surfdata /log/idc1");
	printf("inifile 全国气象站点参数文件名。\n");
	printf("outpath 全国气象站点数据文件存放目录。\n");
	printf("logfile 本程序运行的日志文件名 \n\n"			);
  	
	return -1;
  }

  return 0; 


}
