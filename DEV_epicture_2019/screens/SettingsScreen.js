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

import ImgElem from'../components/imgElem';

export default class SettingsScreen extends Component<{}> {
  constructor(props) {
    super(props);
    this.state = {
      jsonData: [],
      imgList: [],
      favs: [],
      disp_favs: false,
      account_img_url: "",
    };
    this.setJsonData = this.setJsonData.bind(this);
    this.setAccountUrl = this.setAccountUrl.bind(this);
    this.setImgList = this.setImgList.bind(this);
    this.setFavs = this.setFavs.bind(this);
    this.setFavsState = this.setFavsState.bind(this);
  }

  setAccountUrl(url) {
    this.setState({account_img_url: url});
  }
  setJsonData(thejsonData) {
    this.setState({jsonData: thejsonData});
  }
  setImgList(list) {
    this.setState({imgList: list});
  }
  setFavs(fav) {
    this.setState({favs: fav});
  }
  setFavsState(st) {
    if (this.state.disp_favs == false) {
      this.setState({disp_favs: true});
    } else {
      this.setState({disp_favs: false});
    }
  }

  componentDidMount() {
    fetch("https://api.imgur.com/3/account/me/settings", {
      method: 'GET',
      headers: {
        'Authorization': `Bearer ${global.token}`
      }})
      .then((response) => response.json())
      .then((responseJson) => {
              this.setJsonData(responseJson.data);
        }).catch((error) => {
          console.error(error);
        });
    fetch(`https://api.imgur.com/3/account/${global.username}/avatar`, {
      method: 'GET',
      headers: {
        'Authorization': `Bearer ${global.token}`
      }})
      .then((response) => response.json())
      .then((responseJson) => {
              this.setAccountUrl(responseJson.data.avatar);
        }).catch((error) => {
          console.error(error);
        });
    fetch("https://api.imgur.com/3/account/me/images", {
      method: 'GET',
      headers: {
        'Authorization': `Bearer ${global.token}`
      }})
      .then((response) => response.json())
      .then((responseJson) => {
              this.setImgList(responseJson.data);
        }).catch((error) => {
          console.error(error);
        });
    fetch("https://api.imgur.com/3/account/me/gallery_favorites/", {
      method: 'GET',
      headers: {
        'Authorization': `Bearer ${global.token}`
      }})
      .then((response) => response.json())
      .then((responseJson) => {
              this.setFavs(responseJson.data);
        }).catch((error) => {
          console.error(error);
        });
  }

  render() {
    if (this.state.disp_favs == true) {
      return (
        <View style={styles.container}>
          <View>
            <View style={styles.imgCont}>
              <Image style={styles.img} source={{uri: this.state.account_img_url}} />
            </View>
            <View>
              <Text>Name: {this.state.jsonData.account_url}</Text>
            </View>
            <View>
              <Text>Email: {this.state.jsonData.email}</Text>
            </View>
          </View>
          <View style={styles.contentContainer}>
            <View>
              <TouchableOpacity onPress={this.setFavsState}>
                <Text>My images</Text>
              </TouchableOpacity>
              <TouchableOpacity onPress={this.setFavsState}>
                <Text>My Favs</Text>
              </TouchableOpacity>
            </View>
            <View>
              <ScrollView>
                {this.state.favs.map(obj => <ImgElem name={obj.name} url={obj.link}
                  bobj={obj} />)}
              </ScrollView>
            </View>
          </View>
        </View>
      );
    } else {
      return (
        <View style={styles.container}>
          <View>
            <View style={styles.imgCont}>
              <Image style={styles.img} source={{uri: this.state.account_img_url}} />
            </View>
            <View>
              <Text>Name: {this.state.jsonData.account_url}</Text>
            </View>
            <View>
              <Text>Email: {this.state.jsonData.email}</Text>
            </View>
          </View>
          <View style={styles.contentContainer}>
            <View>
              <TouchableOpacity onPress={this.setFavsState}>
                <Text>My images</Text>
              </TouchableOpacity>
              <TouchableOpacity onPress={this.setFavsState}>
                <Text>My Favs</Text>
              </TouchableOpacity>
            </View>
            <View>
              <ScrollView>
                {this.state.imgList.map(obj => <ImgElem name={obj.name} url={obj.link}
                  bobj={obj} />)}
              </ScrollView>
            </View>
          </View>
        </View>
      );
    }
  }
}

const styles = StyleSheet.create({
  container: {
    flex: 1,
    flexDirection: 'column',
    backgroundColor: '#FFF',
  },
  img: {
    width: '100%',
    height: '100%',
  },
  imgCont: {
    width: 50,
    height: 50,
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
