#include <stdio.h>

#include "sslog.h"

int main() {
    // 初始化日志系统
    if (sslog_init("test.log", SSLOG_LEVEL_DEBUG) != 0) {
        fprintf(stderr, "日志初始化失败\n");
        return 1;
    }

    // 测试不同日志级别
    _LOG("调试日志: 程序启动");
    _LOG_W("警告日志: 内存使用率 %.2f%%", 75.3);
    _LOG_E("错误日志: 文件 %s 未找到", "config.conf");

    // 直接调用日志函数
    sslog(SSLOG_LEVEL_FATAL, "致命错误代码: 0x%08X", 0xDEADBEEF);

    // 测试错误情况
    printf("-- 测试错误处理 --\n");
    if (sslog_init("/invalid_path/test.log", SSLOG_LEVEL_DEBUG) == 0) {
        _LOG("此日志不应出现");
        sslog_free();
    }

    // 清理资源
    sslog_free();
    printf("测试完成，请查看 test.log 文件\n");
    return 0;
}
