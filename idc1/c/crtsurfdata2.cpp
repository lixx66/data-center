#include "_public.h"
CLogFile logfile;
struct st_stcode{
	char provname[31];
	char obtid[11];
	char obtname[31];
	double lat;
	double lon;
	double height;
};

vector<struct st_stcode> vstcode;

bool loadSTCode(const char *inifile);

int main(int argc,char *argv[]){

//inifile气象参数文件 outpath logfile

  if(argc!=4){
	printf("Using:./crtsurfdata2 inifile putpath logfile\n");
	printf("Example:/project/idc1/bin/crtsurfdata2 /project/idc1/ini/stcode.ini /tmp/surfdata /log/idc2/crtsurfdata2.log\n\n");

	printf("inifile 全国气象站点参数文件名。\n");
	printf("outpath 全国气象站点数据文件存放目录。\n");
	printf("logfile 本程序运行的日志文件名 \n\n"			);
  	
	return -1;
  }

  if(logfile.Open(argv[3])==false){
  	printf("logfile.Open(%s) failed.\n,argv[3]");
	return -1;
  }

  logfile.Write("crtsurfdata2 开始运行。\n");

  if(loadSTCode(argv[1])==false) return -1;

  logfile.Write("crtsurfdata2 运行结束.   \n");

  return 0; 

};

bool loadSTCode(const char *inifile){
	CFile File;

	if(File.Open(inifile,"r")==false){
		logfile.Write("File.Open(%s) failed.\n",inifile);
		return false;
	}

	char strBuffer[301];
    CCmdStr CmdStr;
    struct st_stcode stcode;

	while(true){
		if(File.Fgets(strBuffer,300,true)==false) break;
        
        logfile.Write("=%s=\n",strBuffer);
        
        CmdStr.SplitToCmd(strBuffer,",",true);
        if(CmdStr.CmdCount()!=6) continue;
        CmdStr.GetValue(0, stcode.provname,30);
        CmdStr.GetValue(1, stcode.obtid,10);
        CmdStr.GetValue(2, stcode.obtname,30);
        CmdStr.GetValue(3,&stcode.lat);
        CmdStr.GetValue(4,&stcode.lon);
        CmdStr.GetValue(5,&stcode.height);

        vstcode.push_back(stcode);
	}
    /*
    for(int ii=0;ii<vstcode.size();ii++){
        logfile.Write("provname=%s,obtid=%s,obtname=%s,lat=%.2f,lon=%.2f,height=%.2f\n",
            vstcode[ii].provname,vstcode[ii].obtid,vstcode[ii].obtname,vstcode[ii].lat,vstcode[ii].lon,vstcode[ii].height        
        );

    }
    */
    return true;
};






