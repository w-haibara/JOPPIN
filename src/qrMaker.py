import sys
import qrcode

argv = sys.argv;
argc = len(argv)

if argc == 2:
    img = qrcode.make(argv[1])
    img.show()
    img.save('qrcode' + argv[1] + '.png')
    sys.exit(0)
else:
    sys.exit(1)

