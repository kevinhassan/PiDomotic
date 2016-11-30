import cv2

# setup video capture
cap0 = cv2.VideoCapture(0)
cap1 = cv2.VideoCapture(1)

posV, posH = 0, 0

while True:

    ret0,im0 = cap0.read()
    ret1,im1 = cap1.read()
    
    if (posV == 200):
        posV = 0

    if (posH > 900):
        posH = 0

    for i in range (6):

        video_name = 'test2-{0}'.format(i)
        cv2.imshow(video_name.format(i),im0)
        cv2.moveWindow(video_name, posH+i*80, i*50)

    for i in range (8):

        video_name = 'test-{0}'.format(i)
        cv2.imshow(video_name.format(i),im1)
        cv2.moveWindow(video_name, 160*i+40, posV+i*50)

    key = cv2.waitKey(10)

    posV += 10
    posH += 8
