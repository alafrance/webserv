#ifndef SERVER_HPP
# define SERVER_HPP

# include "Location.hpp"

using namespace std;

class Server {
public:
	Server() : _autoindex(false), _client_max_body_size(0), _redirect_status(0) {};

	~Server() {};

	void print() {
		cout << "host: " << this->_host << endl;
		cout << "ports: ";
		for (unsigned long i = 0; i < _ports.size(); i++)
			cout << _ports[i] << " ";
		cout << endl;
		cout << "server_names: ";
		for (unsigned long i = 0; i < _server_name.size(); i++)
			cout << _server_name[i] << " ";
		cout << endl;
		cout << "default_pages: " << _default_pages << endl;
		cout << "client_max_body_size: " << _client_max_body_size << endl;
		cout << "redirect_status: " << _redirect_status << endl;
		cout << "redirect: " << _redirect << endl;
		cout << "autoindex: " << _autoindex << endl;

		for (unsigned long i = 0; i < _locations.size(); i++) {
			cout << endl;
			cout << "[LOCATION " << i << "]" << endl;
			_locations[i].print();
		}
	};

	bool mandatory(int index = -1) {
		if (_host.empty() || _server_name.empty() || (index == 0 && _ports.empty()))
			return (false);
		return (true);
	}

	bool isAutoindex() const { return _autoindex; }

	const string &getHost() const { return _host; }

	vector<string> &getServerName() { return _server_name; }

	const string &getDefaultPages() const { return _default_pages; }

	int getClientMaxBodySize() const { return _client_max_body_size; }

	int getRedirectStatus() const { return _redirect_status; }

	const string &getRedirect() const { return _redirect; }

	vector<Location> &getLocations() { return _locations; }

	vector<int> &getPorts() { return _ports; }


	void setAutoindex(bool autoindex) { _autoindex = autoindex; }

	void setHost(const string &host) { _host = host; }

	void setServerName(const vector<string> &serverName) { _server_name = serverName; }

	void setDefaultPages(const string &defaultPages) { _default_pages = defaultPages; }

	void setClientMaxBodySize(int clientMaxBodySize) { _client_max_body_size = clientMaxBodySize; }

	void setRedirectStatus(int redirectStatus) { _redirect_status = redirectStatus; }

	void setRedirect(const string &redirect) { _redirect = redirect; }

	void setLocations(const vector<Location> &locations) { _locations = locations; }

	void setPorts(const vector<int> &ports) { _ports = ports; }

private:
	bool _autoindex;
	string _host;
	vector<string> _server_name;
	string _default_pages;
	int _client_max_body_size;
	int _redirect_status;
	string _redirect;
	vector<Location> _locations;
	vector<int> _ports;
};

#endif