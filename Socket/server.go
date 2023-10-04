package main

import (
	"fmt"
	"net"
)

func process(conn net.Conn) {
	defer conn.Close()
	for {
		buf := make([]byte, 512)
		n, err := conn.Read(buf)
		if err != nil {
			if err.Error() == "EOF" {
				fmt.Println("客户端已退出连接")
				return
			}
			fmt.Println("read err: ", err)
			return
		}
		fmt.Println("read: ", string(buf[:n]))
	}
}
func main() {
	fmt.Printf("server start...\n")
	ln, err := net.Listen("tcp", ":8080")
	if err != nil {
		fmt.Println("listen failed, err: ", err)
		return
	}
	for {
		conn, err := ln.Accept()
		if err != nil {
			fmt.Println("accept failed, err:", err)
			continue
		}
		go process(conn)
	}

}
