package api

import (
	"fmt"

	"goSockSvr/iface"
	"goSockSvr/network"
	pb "goSockSvr/proto/bin"
	"time"
)

type PingRouter struct {
	network.BaseRouter
}

func (p *PingRouter) Handler(req iface.IRequest) {
	pingReq := &pb.Ping{}
	UnmarshalProtoData(req.GetData(), pingReq)
	fmt.Printf("recv ping:{%v}\n",pingReq)

	pingRes := &pb.Ping{}
	msgId := uint32(pb.MessageID_PING)
	pingRes.TimeStamp = pingReq.GetTimeStamp()
	if pingReq.Hello == "ping"{
		pingRes.Hello = "pong"
	}
	fmt.Printf("send msgId=%d,{%s}\n", msgId,pingRes)
	req.GetConnection().SendMsg(msgId, MarshalProtoData(pingRes))

	sceneCmd := &pb.Scene{}
	msgId = uint32(pb.MessageID_SCENE)
	sceneCmd.TimeStamp = time.Now().UnixMicro()
	sceneCmd.SceneName = "scene01"
	fmt.Printf("send msgId=%d,{%s}\n", msgId,sceneCmd)
	req.GetConnection().SendMsg(msgId, MarshalProtoData(sceneCmd))
}
