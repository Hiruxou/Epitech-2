<?php 

	/**
	* 
	*/
	class imapClass
	{
		private $mailbox;

		public function __construct($server, $user, $password)
		{
			$this->mailbox = @imap_open($server, $user, $password) or die ("Error on connection");
		}

		public function __destruct()
		{
			imap_close($this->mailbox);			
		}

		public function getMessage($first, $last, $message="")
		{
			if ($message)
			{
				$range = $message;
			}
			else 
			{
				$MC = imap_check($this->mailbox);
				$range =  $first.":".$last;
			}
			$response = imap_fetch_overview($this->mailbox, $range);
    		foreach ($response as $msg) 
    			$result[$msg->msgno] = (array)$msg;
        	return $result;
		}

		public function totalMessages()
		{
			return imap_num_msg($this->mailbox);
		}

		public function deleteMessage($id)
		{
			$status = imap_setflag_full($this->mailbox, $id, '\\Deleted');
    		imap_expunge($this->mailbox);

    		header("Location: /"); /* Redirect browser */

			/* Make sure that code below does not get executed when we redirect. */
    		return $status;
		}

		public function totalUnread()
		{
			$res = imap_search($this->mailbox, 'UNSEEN');
			if ($res === false)
				return (0);
			return count($res);
		}

		public function getUnreadMessages(){
			$emails = array();
	        if ($headers = imap_check($this->mailbox)){
	            $lastnr = $headers->Nmsgs;
	            if ($mails=imap_fetch_overview($this->mailbox,"1:".$lastnr,0)){
	                while (list($key, $val) = each($mails)) {
	                   if (++$key>=0&&$header= imap_header($this->mailbox, $key)){
	                        if($header->Unseen=='U'||$header->Recent=='R'){
	                      	 	$emails[] = array("date" => $val->date, "subject" => $val->subject, "msgno" => $val->msgno, "from" => $val->from);
	                        }
	                    }
	                }
	            }
	        }
	        return $emails;
	    } 

	    public function check_type($structure)
		{
		  if($structure->type == 1)
		    {
		     return(true);
		    }
			else
		    {
		     return(false);
		    }
		}

	    public function readMessage($messageid)
		{
		   $message = array();
   
		   $header = imap_header($this->mailbox, $messageid);
		   $structure = imap_fetchstructure($this->mailbox, $messageid);

		   $message['subject'] = $header->subject;
		   $message['fromaddress'] =   $header->fromaddress;
		   $message['toaddress'] =   $header->toaddress;
		   //$message['ccaddress'] =   $header->ccaddress;
		   $message['date'] =   $header->date;
		   $message['id'] = $messageid;

		  if ($this->check_type($structure))
		  {
		   $message['body'] = imap_fetchbody($this->mailbox,$messageid, "2"); ## GET THE BODY OF MULTI-PART MESSAGE
		   if(!$message['body']) {$message['body'] = '[NO TEXT ENTERED INTO THE MESSAGE]\n\n';}
		  }
		  else
		  {
		   $message['body'] = imap_body($this->mailbox, $messageid);
		   if(!$message['body']) {$message['body'] = '[NO TEXT ENTERED INTO THE MESSAGE]\n\n';}
		  }
		  
		  return $message;
		}
	}

	// $imap = new imapClass();
	// $unread = $imap->totalUnread();
	// $total = $imap->totalMessages();
	// $unreadMess = array_reverse($imap->getUnreadMessages());
	// $mess = array_reverse($imap->getMessage($total - $unread - 10, $total - $unread));
	// echo "You have ".$unread. " new messages ";

	// echo "<h1> New Messages </h1>";
	// for ($i = 0; $i <= $unread ; $i++)
	// 	echo imap_utf8($unreadMess[$i]["subject"])."</br>";

	// echo "<h1> Last Messages </h1>";
	// for ($i = 0 ; $i <= 10 ; $i++)
	// {
	// 	echo "<a href='?mail=".$mess[$i]["msgno"]."'>".imap_utf8($mess[$i]["subject"])."</a></br>";
	// }

	// if (isset($_GET['mail']))
	// 	$imap->readMessages($_GET['mail']);
 ?>