import React, { Component } from 'react';
import { Platform, StatusBar, StyleSheet, View, WebView, Modal } from 'react-native';

import AppNavigator from '../navigation/AppNavigator';

let token = null;
var CLIENT_ID = "0c17565240bb912";
var CLIENT_SECRET = "3e3cd919e00f9467e6a4c20daae2e8304665a183";
var REQUEST_RESPONSE_TYPE = "token";

function get_access_tkn(url, param)
{
    var vars = {};

    url.replace(/[?&]+([^=&]+)=?([^&]*)?/gi, function( m, key, value ) {
            vars[key] = value !== undefined ? value : '';
        }
    );
    if ( param ) {
        return vars[param] ? vars[param] : null
    }
    return vars;
}

class LoginScreen extends Component
{
    state = {
        modalVisible: true,
    }
    toggleModal(visible) {
        this.setState({ modalVisible: visible });
    }
    render() {
        if (token == null) {
            return (
            <Modal
                animationType={'slide'} transparent={false}
                visible={this.state.modalVisible}
                onRequestClose = {() => { console.log("Modal has been closed.") } }
                >
                <WebView
                    source={{uri: "https://api.imgur.com/oauth2/authorize?client_id=" + CLIENT_ID + "&response_type=" + REQUEST_RESPONSE_TYPE}}
                    style={{marginTop: 20}}
                    onNavigationStateChange={(e) => {
                        var tmp_uri = e.url.replace('#', '?');
                        token = get_access_tkn(tmp_uri, "access_token");
                        if (token != null) {
                            global.user_name = get_access_tkn(tmp_uri, "account_username");
                            global.token = token;
                            this.toggleModal(false)
                        }
                    }}
                />
            </Modal>

            );
        } else {
            return (
                <View style={styles.container}>
                    {Platform.OS === 'ios' && <StatusBar barStyle="default" />}
                    <AppNavigator />
                </View>
            );
        }
    }
}

export default LoginScreen;

const styles = StyleSheet.create({
  container: {
    flex: 1,
    backgroundColor: '#fff',
  },
});
