import React, { Component } from 'react';
import {
  Image,
  Platform,
  ScrollView,
  StyleSheet,
  Text,
  TouchableOpacity,
  View,
} from 'react-native';

import { MonoText } from '../components/StyledText';
import SearchBar from 'react-native-searchbar';

import token from './LoginScreen.js';
import ImgElem from'../components/imgElem';

export default class HomeScreen extends Component<{}> {

  constructor(props) {
    super(props);
    this.state = {
      jsonData: [],
      page: 1,
    };
    this.setJsonData = this.setJsonData.bind(this);
    this.nextPage = this.nextPage.bind(this);
    this.prevPage = this.prevPage.bind(this);
  }

  setJsonData(thejsonData) {
    this.setState({jsonData: thejsonData});
  }

  nextPage(no) {
    var val = this.state.page + 1;

    if (val > 1) {
      this.setState({page: val});
      fetch(`https://api.imgur.com/3/gallery/top/viral/day/${this.state.page}`, {
        method: 'GET',
        headers: {
          'Authorization': `Bearer ${global.token}`
        }})
        .then((response) => response.json())
        .then((responseJson) => {
                this.setJsonData(responseJson.data);
                global.username = responseJson.data.account_url;
          }).catch((error) => {
            console.error(error);
          });
    }
  }
  prevPage(no) {
    var val = this.state.page - 1;

    if (val > 1) {
      this.setState({page: val});
      fetch(`https://api.imgur.com/3/gallery/top/viral/day/${this.state.page}`, {
        method: 'GET',
        headers: {
          'Authorization': `Bearer ${global.token}`
        }})
        .then((response) => response.json())
        .then((responseJson) => {
                this.setJsonData(responseJson.data);
                global.username = responseJson.data.account_url;
          }).catch((error) => {
            console.error(error);
          });
    }
  }

  componentDidMount() {
    fetch(`https://api.imgur.com/3/gallery/top/viral/day/${this.state.page}`, {
      method: 'GET',
      headers: {
        'Authorization': `Bearer ${global.token}`
      }})
      .then((response) => response.json())
      .then((responseJson) => {
              this.setJsonData(responseJson.data);
              global.username = responseJson.data.account_url;
        }).catch((error) => {
          console.error(error);
        });
  }

  render() {
    return (
      <View style={styles.container}>
        <View>
          <TouchableOpacity onPress={this.nextPage}>
            <Text>NEXT PAGE</Text>
          </TouchableOpacity>
          <TouchableOpacity onPress={this.prevPage}>
            <Text>PREV PAGE</Text>
          </TouchableOpacity>
        </View>
        <View style={styles.contentContainer}>
          <ScrollView>
            {this.state.jsonData.map(obj => <ImgElem name={obj.name}
              url={obj.link} bobj={obj} mdr={obj.images_count}/>)}
          </ScrollView>
        </View>
      </View>
    );
  }
}

HomeScreen.navigationOptions = {
  title: 'Home',
};

const styles = StyleSheet.create({
  container: {
    flex: 1,
    flexDirection: 'column',
    backgroundColor: '#FFF',
  },
  contentContainer: {
    backgroundColor: 'white',
    paddingTop: 5,
    paddingBottom: 5,
    paddingLeft: 5,
    paddingRight: 5,
    flex:1,
    flexDirection: 'column',
  },
  scrooll: {
    marginHorizontal: 0,
  },
});

/*
 *
    var name = null;
    let xhr = new XMLHttpRequest();
     xhr.onreadystatechange = function() {
      console.log("status: " + this.status);
      if (this.readyState == 4 && this.status == 200) {
        // Typical action to be performed when the document is ready:
        console.log("response1: " + xhr._response);
        console.log("response2: " + xhr.response.data.account_url);
        name = xhr.response.data.account_url;
      }
    };
    xhr.open("GET", "https://api.imgur.com/3/account/me/settings", false);
    xhr.setRequestHeader("Authorization", "Bearer " + global.token);
    xhr.responseType = 'json';
    xhr.send();
 */
