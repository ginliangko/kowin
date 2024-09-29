Share Folder:
	sudo vmhgfs-fuse .host:/ /mnt/hgfs/ -o allow_other -o uid=1000
	cd /mnt/hgfs/share

	Install:
		sudo mkdir -p /mnt/hgfs/
		sudo vmhgfs-fuse .host:/ /mnt/hgfs/ -o allow_other -o uid=1000

make clean;make -C plume BOARDS="frodo_dvt" VARIANT=dev SECURITY=huffman

make clean;make -C plume TOOLCHAIN=/opt/toolchains/gcc-arm-none-eabi-9-2020-q2-update/bin/arm-none-eabi  BOARDS=frodo_evt2 VARIANT=dev SECURITY=encrypt

git clone master:
	git clone https://github.com/plume-design/frodo-firmware


switch to branch:
	git branch -a				;查看local and remote branch
	git checkout --track origin/my-branch-name		//switch to the remote branch:

Env install:
	- GNU Arm Embedded Toolchain download https://developer.arm.com/downloads/-/gnu-rm
		- sudo tar xjf gcc-arm-none-eabi-your-version.bz2 -C /usr/share/
		- echo 'export PATH=$PATH:/usr/share/gcc-arm-none-eabi/bin' | sudo tee -a /etc/profile.d/gcc-arm-none-eabi.sh

	- J-Link Software (included J-Link Flash Lite, SWOViewer and ...) download
	- Python3 download
	- pycryptodome package (pip3 install pycryptodome)


make clean;make -C plume TOOLCHAIN=/opt/toolchains/gcc-arm-none-eabi-10.3-2021.10/bin/arm-none-eabi VARIANT=prod SECURITY=encrypt

make clean;make -C plume TOOLCHAIN=/opt/toolchains/gcc-arm-none-eabi-10.3-2021.10/bin/arm-none-eabi VARIANT=dev SECURITY=huffman