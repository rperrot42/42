installation:
	apt install vim
	apt install openssh-serveur
	apt install ufw
	apt install sudo
	apt install libpam-pwquality

config ssh:
	vim /etc/ssh/sshd_config "#Port 22" -> "Port 4242"
sudo systemctl restart ssh