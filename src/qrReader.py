# -*- coding: utf-8 -*-
import cv2
import zbar

scanner = zbar.ImageScanner()
scanner.parse_config('enable')
cap = cv2.VideoCapture(0)
captured = False

while True:
    ret, camera = cap.read()
    gray = cv2.cvtColor(camera, cv2.COLOR_BGR2GRAY)
    rows, cols = gray.shape[:2]
    image = zbar.Image(cols, rows, 'Y800', gray.tostring())
    scanner.scan(image)

    #cv2.namedWindow('camera', cv2.WINDOW_NORMAL)
    #cv2.setWindowProperty('camera', cv2.WND_PROP_FULLSCREEN, 1)
    #cv2.imshow("camera", camera)

    for symbol in image:
        
        #print('%s' % symbol.data)
        
        f = open('userID.txt', 'w')
        f.write('%s' % symbol.data)
        f.close()
        captured = True

    if captured:
        break

    if cv2.waitKey(1) == 27:
        break


cap.release()

cv2.destroyAllWindows()
