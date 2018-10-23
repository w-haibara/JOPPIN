import sys
import qrcode
import subprocess

argv = sys.argv;
argc = len(argv)

if argc == 2:
	img = qrcode.make(argv[1])
	img.show()
	name ='qrcode' + argv[1] + '.png'
	img.save(name)
	subprocess.call(["mv", name, "./qrCode"])
	sys.exit(0)
else:
    sys.exit(1)
