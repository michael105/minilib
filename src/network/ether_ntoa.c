//+depends network
//+def
char* ether_ntoa( const struct ether_addr *e ){
	char t[] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 
		'a', 'b', 'c', 'd', 'e', 'f' };

	for ( int i = 0; i < 6; i++ ){
		mlgl->ether_ntoa_addr[i*3] = t[ e->ether_addr_octet[i] & 0xF ]; 
		mlgl->ether_ntoa_addr[i*3+1] = t[ (e->ether_addr_octet[i] >> 4 ) & 0xF ];
		mlgl->ether_ntoa_addr[i*3+2] = ':';
	}
	mlgl->ether_ntoa_addr[17] = 0;

	return( mlgl->ether_ntoa_addr );
}

