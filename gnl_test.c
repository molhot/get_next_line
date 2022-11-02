#include<stdio.h>
#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>

int main()
{
    static int fd;
    char buff[2 + 1];
    int ret;

    fd = open("new.txt", O_RDONLY);
    if(fd == -1)
    {
        return 0;
    }
    //ここの部分がbuffereに合わせて読み込む部分
    //うまく切り取り（保存させ、)一行ずつ吐き出させていく必要がある:|
    while((ret = read(fd, buff, 2)) > 0)
    {
        buff[ret] = '\0';
        printf("%s\n", buff);
    }
}