package api

import (
	"fmt"

	"goSockSvr/iface"
	"goSockSvr/network"
	pb "goSockSvr/proto/bin"
)

type SceneRouter struct {
	network.BaseRouter
}

func (p *SceneRouter) Handler(req iface.IRequest) {
	reqMsg := &pb.Scene{}
	UnmarshalProtoData(req.GetData(), reqMsg)
	fmt.Println("recv: ",reqMsg)
}
