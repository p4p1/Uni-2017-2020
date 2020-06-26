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

import token from './LoginScreen.js';
import ImgElem from'../components/imgElem';
import EpiBtn from '../components/EpiBtn';

//import ImagePicker from 'react-native-image-picker';

export default class LinksScreen extends Component<{}> {
  constructor(props) {
    super(props);
    this.options = {
      title: 'Select Avatar',
      customButtons: [{ name: 'fb', title: 'Choose Photo from Facebook' }],
      storageOptions: {
        skipBackup: true,
        path: 'images',
      },
    };
    this.state = {
      file: [],
    };
  }

  onPress = () => {
    /*ImagePicker.showImagePicker(this.options, (response) => {
      console.log('Response = ', response);

      if (response.didCancel) {
        console.log('User cancelled image picker');
      } else if (response.error) {
        console.log('ImagePicker Error: ', response.error);
      } else if (response.customButton) {
        console.log('User tapped custom button: ', response.customButton);
      } else {
        const source = { uri: 'data:image/jpeg;base64,' + response.data };
        this.setState({
          file: source,
        });
      }
    });*/
    console.log("upload");
  }


  render() {
    return (
      <EpiBtn name="Upload" />
    );
  }
}

LinksScreen.navigationOptions = {
  title: '',
};

const styles = StyleSheet.create({
  container: {
    flex: 1,
    paddingTop: 15,
    backgroundColor: '#fff',
  },
});
