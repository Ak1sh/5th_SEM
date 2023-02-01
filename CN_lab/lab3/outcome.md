## Configuring IP address to Routers in Packet Tracer and configuring static routes in multiple router topology
<ul>
<li>A toplogy was created using three Router-PT and two PC's connected to two routers using copper cross-over connections and serial DCE connections<br>
<img src="https://github.com/18nanma/College-Labs/blob/master/Computer%20Networks%20-1BM18CS031/CN-Lab-3/initial%20topology.png"/>
</li>
<li>Different default gateways were configured for both the PC's .</li>
<li>A unique IP address was configured for each PC.</li>
<li>IP address was configured for each interface using CLI</li>
<li>Pinging PC1 from PC0 gave destination host unreachable</li>
<li>ip routes for each router was viewed using the command: show ip route</li>
<li>Static ip route was configured for each router using CLI commands: ip route destination_network subnet_mask next_hop_address </li>
<img src="https://github.com/18nanma/College-Labs/blob/master/Computer%20Networks%20-1BM18CS031/CN-Lab-3/router%200%20config.png"/>
<img src="https://github.com/18nanma/College-Labs/blob/master/Computer%20Networks%20-1BM18CS031/CN-Lab-3/router%202%20final%20configs.png"/>
<br>
<li>Pinging PC0 from PC1 and PC1 from PC0 gave the required ping responses</li>
<img src="https://github.com/18nanma/College-Labs/blob/master/Computer%20Networks%20-1BM18CS031/CN-Lab-3/ping.png"/>
<li>The final topology</li>
<img src="https://github.com/18nanma/College-Labs/blob/master/Computer%20Networks%20-1BM18CS031/CN-Lab-3/final%20topology.png"/>
</ul>

### Learning outcomes
<ul>
<li>Creating a topology with multiple routers.</li>
<li>Configuring default gateway and ip address.</li>
<li>Configuring ip address for the interfaces</li>
<li>Pinging gives destination host unreachable if the device networks are not directly connected</li>
<li>Configuring static ip routes</li>
<li>On configuring the static ip routes, pinging gives the required response</li>
</ul>
