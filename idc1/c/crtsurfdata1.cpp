
#include "_public.h"
CLogFile logfile;


int main(int argc,char *argv[]){

//inifile气象参数文件 outpath logfile

  if(argc!=4){
	printf("Using:./crtsurfdata1 inifile putpath logfile\n");
	printf("Example:project/idc1/bin/crtsurfdata1 /project/idc1/ini/stcode.ini /tmp/surfdata /log/idc1/crtsurfdata1.log\n\n");

	printf("inifile 全国气象站点参数文件名。\n");
	printf("outpath 全国气象站点数据文件存放目录。\n");
	printf("logfile 本程序运行的日志文件名 \n\n"			);
  	
	return -1;
  }

  if(logfile.Open(argv[3])==false){
  	printf("logfile.Open(%s) failed.\n,argv[3]"); return -1;
  }

  logfile.Write("crtsurfdata1 开始运行。\n");

  for(int ii=0;ii<560000000;ii++){

	  logfile.Write("这是第%010d条日志\n",ii+"abcd");
  }
  logfile.Write("crtsurfdata1 运行结束.   \n");


  return 0; 


}
