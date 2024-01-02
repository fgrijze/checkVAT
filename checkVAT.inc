<?php
function checkVAT ($vatNumber) {
	$country = substr($vatNumber, 0, 2);
	$number = substr($vatNumber, 2);
	
	try {
		$soapClient = new SoapClient("https://ec.europa.eu/taxation_customs/vies/checkVatService.wsdl");
		
		$requestParams = [
			"countryCode" => (string) $country,
			"vatNumber" => (string) $number
		];
		
		$soapResult = $soapClient->checkVatApprox($requestParams);
		
		if ($soapResult->valid == "1")
			return true;
		else
			return false;
	} catch (SoapFault $e) {
		echo "An error occurred: " . htmlspecialchars($e->getMessage());
	}
}
