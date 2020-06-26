import React, {Component} from 'react';
import {
  Image,
  StyleSheet,
  Text,
  TouchableOpacity,
  View,
  ScrollView,
} from 'react-native';


export default class ImgElem extends Component<{}> {
  constructor (props) {
    super(props);
  }

  onPress = () => {
    fetch(`https://api.imgur.com/3/image/${this.props.bobj.id}/favorite/`, {
      method: 'POST',
      headers: {
        'Authorization': `Bearer ${global.token}`
      }})
      .then((response) => response.json())
      .then((responseJson) => {
          console.log("INSIDE ONPRESS");
        }).catch((error) => {
          console.error(error);
        });
  }

  render() {
    if (this.props.mdr == undefined) {
      return (
          <View style={styles.imgElem}>
            <View style={styles.txtCont}>
              <Text>Name: {this.props.name} | {this.props.bobj.type}</Text>
            </View>
            <View style={styles.imgCont}>
                <Image style={styles.images}
                  source={{uri: this.props.url }} />
            </View>
            <View style={styles.favCont}>
              <TouchableOpacity onPress={this.onPress}>
                <Text>Favourite image</Text>
              </TouchableOpacity>
            </View>
          </View>
      );
    } else {
      return (<View></View>);
    }
  }
}

const styles = StyleSheet.create({
  imgElem: {
    flexDirection: 'column',
    justifyContent: 'center',
    backgroundColor: 'gray',
    paddingTop: 15,
    paddingBottom: 15,
    paddingLeft: 15,
    paddingRight: 15,
    marginBottom: 10,
    height: 500,
  },
  images : {
    height: '100%',
    width: '100%',
  },
  txtCont: {
    paddingTop: 1,
    paddingBottom: 1,
    paddingLeft: 1,
    paddingRight: 1,
  },
  imgCont: {
    paddingTop: 1,
    paddingBottom: 1,
    paddingLeft: 1,
    paddingRight: 1,
  },
  favCont: {
    paddingTop: 1,
    paddingBottom: 1,
    paddingLeft: 1,
    paddingRight: 1,
  }
});
