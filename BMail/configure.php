#!/usr/bin/env php5
<?php
function read($lenght = 255)
{
	if (!isset($GLOBALS['StdinPointer']))
		$GLOBALS['StdinPointer'] = fopen("php://stdin", "r");
	$line = fgets($GLOBALS['StdinPointer'], $lenght);
	return trim($line);
}
echo "Enter server: ";
$server = read();
echo "Enter port: ";
$port = read();
echo "Enter mail address or username:";
$user = read();
echo "Enter password:";
system('stty -echo');
$pwd = read();
system('stty echo');
echo "Is it a pop3 server? (y/n)";
$pop = read();
if ($pop == "y")
	$pop = true;
else
	$pop = false;
echo "Is there SSL on server? (y/n)";
$ssl = read();
if ($ssl == "y")
	$ssl = true;
else
	$ssl = false;
include 'class/Parser.php';
$parser = new Parser();
$parser->generate($server, $port, $user, $pwd, $pop, $ssl);
echo "Thank you, you can now watch your mails.";
?>