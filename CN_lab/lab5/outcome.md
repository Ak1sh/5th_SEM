## Configuring DHCP within a LAN
<ul>
<li><h3>A toplogy was created using a Router, a Switch, a Server and four PC's connected as shown in the figure</h3><br>
<img src="https://github.com/18nanma/College-Labs/blob/master/Computer%20Networks%20-1BM18CS031/CN-Lab-5/dhcp%20exp-1/topology.png"/><br>
</li>
<li><h3>The Router interface was configured using CLI</h3><br>
<img src="https://github.com/18nanma/College-Labs/blob/master/Computer%20Networks%20-1BM18CS031/CN-Lab-5/dhcp%20exp-1/router%20config.png" /><br>
<li><h3>The Server was configured specifying the default gateway, DNS server, TFTP server as shown below</h3></li>
<img src="https://github.com/18nanma/College-Labs/blob/master/Computer%20Networks%20-1BM18CS031/CN-Lab-5/dhcp%20exp-1/server%20config.png" /><br>
<br>
<li><h3>The PCs request the Server for ip. Upon request, an ip address was successfully assigned to the PC</h3></li>
<img src="https://github.com/18nanma/College-Labs/blob/master/Computer%20Networks%20-1BM18CS031/CN-Lab-5/dhcp%20exp-1/dhcp%20connection.png"/><br>
<br>
</ul>

### Learning outcomes
<ul>
<li>Creating a topology with router, switch, server and PCS.</li>
<li>Configuring the server.</li>
<li>4 steps in DHCP</li>
<ul>
<li>D - Discover the server</li>
<li>O - Offer the IP address</li>
<li>R - Request ip</li>
<li>A - Acknowledgement</li>
</ul>
<li>Individual PC request the Server for an ip address</li>
<li>An ip address is assigned to the PC from a pool of IP addresses by the DHCP server</li>
</ul>
