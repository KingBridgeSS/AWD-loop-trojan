package main

import (
	"fmt"
	"github.com/gin-gonic/gin"
	"log"
	"os"
)

func setupRouter() *gin.Engine {
	r := gin.Default()
	r.POST("/", func(c *gin.Context) {
		flag := c.PostForm("flag")
		if flag != "" {
			// If the file doesn't exist, create it, or append to the file
			file, err := os.OpenFile("flags.txt", os.O_APPEND|os.O_CREATE|os.O_WRONLY, 0666)
			if err != nil {
				log.Fatal(err)
			}
			_, err = file.WriteString(flag + "\n")
			if err != nil {
				return
			}
		} else {
			fmt.Println("empty")
		}
		c.String(200, "ok")
	})
	return r
}
func main() {
	r := setupRouter()
	r.Run(":2334")
}
