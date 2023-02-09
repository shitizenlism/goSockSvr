package api

import (
	// "encoding/json"
	"goSockSvr/logs"
	"google.golang.org/protobuf/proto"
)

func MarshalProtoData(str proto.Message) []byte {
	marshal, err := proto.Marshal(str)
	if err != nil {
		logs.PrintLogErrToConsole(err)
		return []byte{}
	}
	return marshal
}

func UnmarshalProtoData(byte []byte, target proto.Message) {
	// err := json.Unmarshal(byte, target)
	err := proto.Unmarshal(byte, target)
	if err != nil {
		logs.PrintLogErrToConsole(err)
	}
}
