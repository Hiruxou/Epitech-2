<?php
/**
* Parser
*/
class 						Parser
{
	const FILE = '../config.json';
	private $json;


	function __construct()
	{
		if (file_exists(self::FILE))
		{
			$file = file_get_contents(self::FILE);
			$this->json = json_decode($file, true);
		}
	}

	// rajouter gestion SSL !!!!
	public function 		generate($server, $port, $user, $password, $pop = false, $ssl = false)
	{
		$yml = array(
			"server" => $server,
			"port" => $port,
			"user" => $user,
			"password" => $password,
			"pop3" => $pop,
			"ssl" => $ssl,
			);
		$generated = json_encode($yml);
		$file = fopen('config.json', 'w+');
		fputs($file, $generated);
		fclose($file);
	}

	// repercuter la modif SSL
	public function 		getServer()
	{
		$str = "{".$this->json['server'].":".$this->json['port'].($this->json['pop3'] ? "/pop3" : "/imap").($this->json['ssl'] ? "/ssl" : "")."}INBOX";
		return ($str);
	}

	public function 		getServerTrash()
	{
		$str = "{".$this->json['server'].":".$this->json['port'].($this->json['pop3'] ? "/pop3" : "/imap").($this->json['ssl'] ? "/ssl" : "")."}TRASH";
		return ($str);	
	}

	public function 		getUser()
	{
		return ($this->json['user']);
	}

	public function 		getPassword()
	{
		return ($this->json['password']);
	}
}