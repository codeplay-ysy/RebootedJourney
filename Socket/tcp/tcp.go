package main

import (
	"bufio"
	"fmt"
	"net"
	"os"
	"strings"
)

func main() {
	conn, err := net.Dial("tcp", "192.168.1.7:8080")
	if err != nil {
		fmt.Println("dial failed: ", err)
		return
	}
	defer conn.Close()
	inputReader := bufio.NewReader(os.Stdin)
	for {
		input, _ := inputReader.ReadString('\n')
		trimedinput := strings.Trim(input, "\r\n")
		if trimedinput == "Q" {
			return
		}
		_, err := conn.Write([]byte(trimedinput))
		if err != nil {
			fmt.Println("err conn.Write: ", err)
			return
		}
	}
}
