package main

import (
	"fmt"
	"goSockSvr/api"
	"goSockSvr/iface"
	"goSockSvr/logs"
	"goSockSvr/network"
	pb "goSockSvr/proto/bin"
	"runtime"
	"time"
)

func main() {
	s := network.NewServer()
	go func(svr iface.IServer) {
		for range time.Tick(time.Second * 30) {
			logs.PrintLogInfoToConsole(fmt.Sprint("goroutine concurrency: ", runtime.NumGoroutine(), "\tTcpConn concurrency: ", svr.GetConnMgr().Len()))
		}
	}(s)
	
	s.SetOnConnStart(func(conn iface.IConnection) {
		conn.SetProperty("Client", conn.RemoteAddr())
	})
	s.AddRouter(uint32(pb.MessageID_PING), &api.PingRouter{})
	s.SetOnConnStop(func(conn iface.IConnection) {
		logs.PrintLogInfoToConsole(fmt.Sprintf("%v leaves.", conn.GetProperty("Client")))
	})

	s.Server()
}
