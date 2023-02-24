package main

import (
	"fmt"
	"sync"
	"time"

	"google.golang.org/protobuf/proto"
	"goSockSvr/test/goClt/base"
	pb "goSockSvr/proto/bin"
	"goSockSvr/config"
)

func main() {

	wg := &sync.WaitGroup{}
	wg.Add(1)

	for n := 0; n < 1; n++ {
		go func(n int) {
			conn := &base.CustomConnect{}
			conn.NewConnection(config.GetGlobalObject().Host, config.GetGlobalObject().TcpPort)
			defer conn.SetBlocking()

			go func(n int) {
				i := 0
				for {
					i++

					data := &pb.Ping{TimeStamp: time.Now().UnixMicro(), Hello: "ping"}
					marshal, err := proto.Marshal(data)
					if err != nil {
						return
					}
					conn.SendMsg(uint32(pb.MessageID_PING), marshal)
					fmt.Printf("cycle-%d:{%s},",i,data.String())

					time.Sleep(60 * time.Second)
				}
			}(n)
		}(n)
	}

	wg.Wait()
}
