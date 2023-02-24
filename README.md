# goSockSvr
socket server communicate with linux/win client, message packed with protobuf protocol.

# run
## start goSockServer
`
go mod init goSockSvr
go mod tidy
go mod vendor
go run main.go
`

## start go socket client to verify
`
cd test\goClt
go run main.go
`

## start win socket client to verify
1. **build it by vs2019**
* 1>Previous IPDB was built with incompatible compiler, fall back to full compilation.
1>All 245 functions were compiled because no usable IPDB/IOBJ from previous compilation was found.
1>已完成代码的生成
1>tcpclt_vs2019.vcxproj -> D:\github\goSockSvr\test\TcpClt_win\tcpclt_vs2019\x64\Release\tcpclt_vs2019.exe
1>已完成生成项目“tcpclt_vs2019.vcxproj”的操作。
========== 生成: 成功 1 个，失败 0 个，最新 0 个，跳过 0 个 ==========

2. **start goSocket server**
* D:\github\goSockSvr>go run main.go
conf.go:46 {"Debug":false,"Host":"127.0.0.1","TcpPort":"17777","Name":"goSocket-Server","Version":"v0.1","MaxPackSize":2048,"MaxConn":1000,"Worker
server.go:82 new connection-> 127.0.0.1:13853 connID is: 1
recv ping:{timeStamp:1677210649835000 hello:"ping"}
send msgId=1000,{timeStamp:1677210649835000 hello:"pong"}
send msgId=1001,{timeStamp:1677210649865084 sceneName:"scene01"}
main.go:27 127.0.0.1:13853 leaves.
main.go:18 goroutine concurrency: 10    TcpConn concurrency: 0
exit status 0xc000013a

3. **test by win socket client**
* D:\github\goSockSvr\test\TcpClt_win\tcpclt_vs2019\x64\Release>tcpclt_vs2019.exe localhost 17777
host=localhost,port=17777
recv. msg.id=1000,len=15
recv pbData. ts=1677210649835000,hello=pong
recv. msg.id=1001,len=18
recv pbData. ts=1677210649865084,sceneName=scene01


