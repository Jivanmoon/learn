#ifndef ANYTIMER_H
#define ANYTIMER_H

#define JOB_MAX 1024
typedef void at_jobfunc_t(void *);

/**
 * return >= 0 成功，返回任务id
 *        == -1 失败，参数非法
 *        == -2 失败，数组满
 *        == -3 失败，内存空间不足
 */ 
int at_addjob(int sec, at_jobfunc_t *jobp, void *arg);

/**
 * return == 0          成功，指定任务已取消
 *        == -1    失败，参数非法
 *        == -2    失败，指定任务已完成
 *        == -3    失败，没有该任务
 */ 
int at_conceljob(int id);

/**
 * return   == 0        成功，指定任务已成功释放
 *          == -1       失败，参数非法
 *          == -2       失败，没有该任务
 */ 
int at_waitjob(int id);


//可以考虑实现at_pausejob()、at_resume_job()
#endif