package logs

// 打印模式
var printMode = false

/*
SetPrintMode 设置打印模式

true：打印到文件，false：打印到控制台
*/
func SetPrintMode(v bool) {
	printMode = v
}

// PrintLogInfoToConsole 打印到控制台信息
func PrintLogInfoToConsole(msg string) {
	if msg == "" {
		return
	}
	if printMode {
		logInfoToFile(msg)
	} else {
		logInfoToConsole(msg)
	}
}

// PrintLogErrToConsole 打印到控制台错误
func PrintLogErrToConsole(err error, tips ...string) bool {
	if err == nil {
		return false
	}
	if printMode {
		return logErrToFile(err, tips...)
	} else {
		return logErrToConsole(err, tips...)
	}
}

// PrintLogPanicToConsole 打印到控制台Panic
func PrintLogPanicToConsole(err error) {
	if err == nil {
		return
	}
	if printMode {
		logPanicToFile(err)
	} else {
		logPanicToConsole(err)
	}
}

// PrintLogInfoToFile 打印信息到日志文件
func PrintLogInfoToFile(msg string) {
	logInfoToFile(msg)
}

// PrintLogErrToFile 打印错误到日志文件
func PrintLogErrToFile(err error, tips ...string) bool {
	return logErrToFile(err, tips...)
}

// PrintLogPanicToFile 打印Panic到日志文件
func PrintLogPanicToFile(err error) {
	logPanicToFile(err)
}
