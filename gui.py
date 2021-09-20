import pygame
#pygame初始化
pygame.init()


width, height = 1920,1080

#color
white = (255,255,255)
blue = (0,0,255)
black = (0,0,0)
red = (255,0,0)
green = (0,255,0)

#layout

middle = (width/2 , height/2)
left_up = (0 , 0)
left = (0 , height/2)
left_down = (0 , height)
middle_up = (width/2 , 0)
middle_down = (width/2 , height)
right_up = (width , 0)
right = (width , height/2)
right_down = (width , height)

                    
screen = pygame.display.set_mode((width, height)) 
pygame.display.set_caption("network on chip")        

#建立畫布bg
bg = pygame.Surface(screen.get_size())
bg = bg.convert()
bg.fill(black)           
#顯示

font = pygame.font.SysFont("simhei", 50)
text = font.render("Please input your NoC's size", True, green , black)
rect = pygame.Rect(10, 20, 30, 30)


bg.blit(rect,middle)
bg.blit(text,middle_up)


screen.blit(bg, (0,0))
pygame.display.update()

#關閉程式的程式碼
running = True
while running:
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            running = False
pygame.quit() 