package network

import (
	"bytes"
	"fmt"

	"encoding/binary"
	"goSockSvr/config"
	"goSockSvr/iface"
	"goSockSvr/logs"
)

type DataPack struct{}

func (d *DataPack) GetHeadLen() uint32 {
	// id uint32(4字节) + dataLen uint32(4字节)
	return 8
}

// NewDataPack 新数据包
func NewDataPack() *DataPack {
	return &DataPack{}
}

// Pack 封包
func (d *DataPack) Pack(msg iface.IMessage) []byte {
	dataBuff := bytes.NewBuffer([]byte{})

	// 写msgId
	if logs.PrintLogErrToConsole(binary.Write(dataBuff, binary.LittleEndian, msg.GetMsgId())) {
		return nil
	}

	// 写dataLen
	if logs.PrintLogErrToConsole(binary.Write(dataBuff, binary.LittleEndian, msg.GetDataLen())) {
		return nil
	}
	
	// 写data数据
	if logs.PrintLogErrToConsole(binary.Write(dataBuff, binary.LittleEndian, msg.GetData())) {
		return nil
	}
	return dataBuff.Bytes()
}

// UnpackHeader 拆包(获取包头Id,dataLen)
func (d *DataPack) UnpackHeader(binaryData []byte) iface.IMessage {
	dataBuff := bytes.NewReader(binaryData)
	msgData := &Message{}
	
	// 读msgId
	if logs.PrintLogErrToConsole(binary.Read(dataBuff, binary.LittleEndian, &msgData.id)) {
		return nil
	}
	// 读dataLen
	if logs.PrintLogErrToConsole(binary.Read(dataBuff, binary.LittleEndian, &msgData.dataLen)) {
		return nil
	}
	//logs.PrintLogInfoToConsole(fmt.Sprintf("msg.id=%d,msg.len=%d",msgData.id,msgData.dataLen))

	// 检查数据长度是否超出限制
	if config.GetGlobalObject().MaxPackSize > 0 && msgData.dataLen > config.GetGlobalObject().MaxPackSize {
		logs.PrintLogInfoToConsole("msg is too long! throw it away.")
		return nil
	}

	return msgData
}

// Unpack 拆包(获取Id, dataLen, data)
func (d *DataPack) Unpack(binaryData []byte) iface.IMessage {
	dataBuff := bytes.NewReader(binaryData)
	msgData := &Message{}
	
	if logs.PrintLogErrToConsole(binary.Read(dataBuff, binary.LittleEndian, &msgData.id)) {
		return nil
	}

	if logs.PrintLogErrToConsole(binary.Read(dataBuff, binary.LittleEndian, &msgData.dataLen)) {
		return nil
	}
	logs.PrintLogInfoToConsole(fmt.Sprintf("msg.id=%d,msg.len=%d",msgData.id,msgData.dataLen))

	// msgData.data = make([]byte, msgData.dataLen)
	// if logs.PrintLogErrToConsole(binary.Read(dataBuff, binary.LittleEndian, msgData.data)) {
	// 	return nil
	// }
	//节省一次copy，避免反复申请/释放buffer操作。
	//msgData.data = binaryData[GetHeadLen():]   //成员函数不能相互调用吗？
	msgData.data = binaryData[8:]
	// logs.PrintLogInfoToConsole(fmt.Sprintf("msg.data=%v",msgData.data))

	return msgData
}

